#! /bin/bash
ps | grep /bin/bash | grep -v grep | awk '{print $1}' | xargs kill