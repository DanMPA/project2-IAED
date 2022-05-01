# Copyright (C) 2021, Pedro Reis dos Santos
.SUFFIXES: .in .out .diff
MAKEFLAGS += --no-print-directory # No entering and leaving messages
OK="test $< PASSED"
KO="test $< FAILED"
EXE=../../proj2

all:: clean # run regression tests
	@$(MAKE) $(MFLAGS) `ls *.in | sed -e "s/in/diff/"`

.in.diff:
	@-$(EXE) < $< | diff - $*.out > $@
	@if [ `wc -l < $@` -eq 0 ]; then echo $(OK); else echo $(KO); fi;

clean::
	rm -f *.diff
