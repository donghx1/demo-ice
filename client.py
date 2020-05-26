#!/usr/bin/env python
# -*- coding: latin-1 -*-

import sys
import time
import Ice
import Demo

with Ice.initialize(sys.argv) as communicator:
    # base = communicator.stringToProxy("%s:default -h %s -p %s" % ("hello", r"192.168.1.10", 10000))
    base = communicator.stringToProxy("hello:default -p 10000")
    print(type(base))
    hello = Demo.HelloPrx.checkedCast(base)
    if not hello:
        raise RuntimeError("Invalid proxy")
    else:
        start = time.time()
        res = hello.SayHello("liitdar")
        end = time.time()
        spendtime = end-start
        print('********************spend time is %s**************************',str(spendtime))
        print(res)
