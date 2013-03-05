xmppc
=====

A basic console XMPP client based on gloox

How to build
=====
OSX: 
install boost, gloox via port

build using: clang++ -I /opt/local/include/ -L /opt/local/lib -lgloox -lboost_program_options-mt main.cpp -o xmppc
