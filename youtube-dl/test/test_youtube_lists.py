#!/usr/bin/env python

import sys
import unittest
import json

# Allow direct execution
import os
sys.path.append(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))

from youtube_dl.InfoExtractors import YoutubeUserIE, YoutubePlaylistIE, YoutubeIE, YoutubeChannelIE
from youtube_dl.utils import *
from youtube_dl.FileDownloader import FileDownloader

PARAMETERS_FILE = os.path.join(os.path.dirname(os.path.abspath(__file__)), "parameters.json")
with io.open(PARAMETERS_FILE, encoding='utf-8') as pf:
    parameters = json.load(pf)

# General configuration (from __init__, not very elegant...)
jar = compat_cookiejar.CookieJar()
cookie_processor = compat_urllib_request.HTTPCookieProcessor(jar)
proxy_handler = compat_urllib_request.ProxyHandler()
opener = compat_urllib_request.build_opener(proxy_handler, cookie_processor, YoutubeDLHandler())
compat_urllib_request.install_opener(opener)

class FakeDownloader(FileDownloader):
    def __init__(self):
        self.result = []
        self.params = parameters
    def to_screen(self, s):
        print(s)
    def trouble(self, s, tb=None):
        raise Exception(s)
    def extract_info(self, url):
        self.result.append(url)
        return url

class TestYoutubeLists(unittest.TestCase):
    def assertIsPlaylist(self,info):
        """Make sure the info has '_type' set to 'playlist'"""
        self.assertEqual(info['_type'], 'playlist')

    def test_youtube_playlist(self):
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        result = ie.extract('https://www.youtube.com/playlist?list=PLwiyx1dc3P2JR9N8gQaQN_BCvlSlap7re')[0]
        self.assertIsPlaylist(result)
        self.assertEqual(result['title'], 'ytdl test PL')
        ytie_results = [YoutubeIE()._extract_id(url['url']) for url in result['entries']]
        self.assertEqual(ytie_results, [ 'bV9L5Ht9LgY', 'FXxLjLQi3Fg', 'tU3Bgo5qJZE'])

    def test_issue_673(self):
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        result = ie.extract('PLBB231211A4F62143')[0]
        self.assertEqual(result['title'], 'Team Fortress 2')
        self.assertTrue(len(result['entries']) > 40)

    def test_youtube_playlist_long(self):
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        result = ie.extract('https://www.youtube.com/playlist?list=UUBABnxM4Ar9ten8Mdjj1j0Q')[0]
        self.assertIsPlaylist(result)
        self.assertTrue(len(result['entries']) >= 799)

    def test_youtube_playlist_with_deleted(self):
        #651
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        result = ie.extract('https://www.youtube.com/playlist?list=PLwP_SiAcdui0KVebT0mU9Apz359a4ubsC')[0]
        ytie_results = [YoutubeIE()._extract_id(url['url']) for url in result['entries']]
        self.assertFalse('pElCt5oNDuI' in ytie_results)
        self.assertFalse('KdPEApIVdWM' in ytie_results)
        
    def test_youtube_playlist_empty(self):
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        result = ie.extract('https://www.youtube.com/playlist?list=PLtPgu7CB4gbZDA7i_euNxn75ISqxwZPYx')[0]
        self.assertIsPlaylist(result)
        self.assertEqual(len(result['entries']), 0)

    def test_youtube_course(self):
        dl = FakeDownloader()
        ie = YoutubePlaylistIE(dl)
        # TODO find a > 100 (paginating?) videos course
        result = ie.extract('https://www.youtube.com/course?list=ECUl4u3cNGP61MdtwGTqZA0MreSaDybji8')[0]
        entries = result['entries']
        self.assertEqual(YoutubeIE()._extract_id(entries[0]['url']), 'j9WZyLZCBzs')
        self.assertEqual(len(entries), 25)
        self.assertEqual(YoutubeIE()._extract_id(entries[-1]['url']), 'rYefUsYuEp0')

    def test_youtube_channel(self):
        dl = FakeDownloader()
        ie = YoutubeChannelIE(dl)
        #test paginated channel
        result = ie.extract('https://www.youtube.com/channel/UCKfVa3S1e4PHvxWcwyMMg8w')[0]
        self.assertTrue(len(result['entries']) > 90)
        #test autogenerated channel
        result = ie.extract('https://www.youtube.com/channel/HCtnHdj3df7iM/videos')[0]
        self.assertTrue(len(result['entries']) >= 18)

    def test_youtube_user(self):
        dl = FakeDownloader()
        ie = YoutubeUserIE(dl)
        result = ie.extract('https://www.youtube.com/user/TheLinuxFoundation')[0]
        self.assertTrue(len(result['entries']) >= 320)

if __name__ == '__main__':
    unittest.main()
