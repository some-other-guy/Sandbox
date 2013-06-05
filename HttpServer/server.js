var url = require( "url" );
var http = require( "http" );

function start( route, handle )
{
    function onRequest( request, response )
    {
        var pathname = url.parse( request.url ).pathname;
       
        route( handle, pathname, response );
    }
    http.createServer( onRequest ).listen( 8080 );
    console.log( "Server started" );
}
exports.start = start;