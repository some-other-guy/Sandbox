var url = require( "url" );
var http = require( "http" );

function start( route )
{
    function onRequest( request, response )
    {
        var pathname = url.parse( request.url ).pathname;
       
        route( pathname );
        
        response.writeHead( 200, { "Content-Type": "text/plain" });
        response.write( "Hello" );
        response.end();
    }
    http.createServer( onRequest ).listen( 8080 );
    console.log( "Server started" );
}
exports.start = start;