var fs = require('fs');
var lame = require('lame');
var wav = require('wav');
var q = require("q");
var defer = q.defer();

var raw2mp3wrapper = function(query){
    var input = fs.createReadStream(query+".mp3");
    var output = fs.createWriteStream(query+".raw");
    var decoder = new lame.Decoder();
    var writer = new wav.Writer("mp3");
    decoder.pipe(writer).pipe(output);
    input.pipe(decoder);
    defer.resolve();
}

var query = function(res, req, query){
    console.log(query);
    raw2mp3wrapper(query);
    defer.promise.then(function(){
	res.writeHead(200, { 'Content-Type': 'audio/mpeg' });
	res.send("hi");
    });
}

exports.query = query;
