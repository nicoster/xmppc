xmppc
=====

A basic console XMPP client based on gloox

how to build on OS X
=====
install boost, gloox via MacPorts

``clang++ -I /opt/local/include/ -L /opt/local/lib -lgloox /opt/local/lib/libboost_program_options-mt.a main.cpp -o xmppc``

how to run on OS X
=====
install gloox via MacPorts

``./xmppc``