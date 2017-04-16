var peg = require('pegjs');
var fs = require('fs');

var pal_src = ""
var grammar = ""

console.log("[+] Executing Palc IL");

pal_src = fs.readFileSync( __dirname + '/living.pal', "UTF8");
grammar = fs.readFileSync( __dirname + '/pal_grammar.pegjs', "UTF8");

parser = peg.generate(grammar);

ILObj = parser.parse(pal_src);

fs.writeFileSync( __dirname + '/living.pil', JSON.stringify(ILObj), "UTF8");
