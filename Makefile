
.PHONY: all
all: bin/tick
	@echo "Done"

.PHONY: run
run: bin/tick
	@./$^

.PHONY: clean
clean:
	@rm  -fR bin/
	@echo "Project cleaned"

bin/tick: main.c board.c
	@mkdir -p	$(dir $@)
	@gcc		-pthread $^ -o $@