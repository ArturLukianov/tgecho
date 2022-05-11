src = $(wildcard *.c)
obj = $(src:.c=.o)

LDFLAGS = -lcurl

tgecho: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) tgecho

PREFIX = /usr/local

.PHONY: install
install: tgecho
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	cp $< $(DESTDIR)$(PREFIX)/bin/tgecho

.PHONY: uninstall
uninstall:
	rm -f $(DESTDIR)$(PREFIX)/bin/tgecho

