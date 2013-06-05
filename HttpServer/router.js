function route( handle, pathname, response )
{
    if( typeof handle[pathname] == 'function' )
    {
        handle[pathname]( response );
    }
    else
    {
        response.writeHead( 404, { "Content-Type": "text/plain" });
        response.write( "Page Not Found " + pathname );
        response.end();
    }
}
exports.route = route;