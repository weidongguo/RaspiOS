var http = require ("http");
var url = require("url");
var nodeStatic = require("node-static");
var queries = require('./queries');

var staticFileServer = new nodeStatic.Server("./client", {cache:0});

function handler(req,resp){
    var obj = url.parse(req.url);
    console.log("path name\t:\t" + obj.pathname);	
    console.log("query string\t:\t" + obj.search);
    
    if( obj.search != undefined && obj.pathname == "/query"){
	q = obj.search.replace('?','');
        queries.query(req, resp, q);
        resp.end();
    }
    else{
	//let the static file server handle the loading of static pages
	staticFileServer.serve(req,resp);
    }
}

server = http.createServer(handler);
server.listen(8000);
