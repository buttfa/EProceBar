all_test:
	@make -B common_procebar_test
	@sleep 1
	@make -B color_procebar_test
	@sleep 1
	@make -B common_transmit_test
	@sleep 1
	@make -B transmit_procebar_test
	@sleep 1
	@make -B task_procebar_test
	@sleep 1

# 测试common_procebar
common_procebar_test:
	@clear
	@echo "common_procebar_test"
	@gcc -o common_procebar_test common_procebar_test.c ../eprocebar/procebar.c ../eprocebar/procebar_style/common_procebar.c -I ../eprocebar -I ../eprocebar/procebar_style
	@./common_procebar_test
	@rm -rf common_procebar_test
	@echo "common_procebar_test done"

# 测试color_procebar
color_procebar_test:
	@clear
	@echo "color_procebar_test"
	@gcc -o color_procebar_test color_procebar_test.c ../eprocebar/procebar.c ../eprocebar/procebar_style/color_procebar.c -I ../eprocebar -I ../eprocebar/procebar_style
	@./color_procebar_test
	@rm -rf color_procebar_test
	@echo "color_procebar_test done"

# 测试common_transmit
common_transmit_test:
	@clear
	@echo "common_transmit_test"
	@gcc -o common_transmit_test common_transmit_test.c ../eprocebar/procebar.c ../eprocebar/procebar_style/common_procebar.c -I ../eprocebar -I ../eprocebar/procebar_style
	@./common_transmit_test
	@rm -rf common_transmit_test

# 测试transmit_procebar
transmit_procebar_test:
	@clear
	@echo "transmit_procebar_test"
	@gcc -o transmit_procebar_test transmit_procebar_test.c ../eprocebar/procebar.c ../eprocebar/procebar_style/transmit_procebar.c -I ../eprocebar -I ../eprocebar/procebar_style
	@./transmit_procebar_test
	@rm -rf transmit_procebar_test
	@echo "transmit_procebar_test done"

# 测试task_procebar
task_procebar_test:
	@clear
	@echo "task_procebar_test"
	@gcc -o task_procebar_test task_procebar_test.c ../eprocebar/procebar.c ../eprocebar/procebar_style/task_procebar.c -I ../eprocebar -I ../eprocebar/procebar_style
	@./task_procebar_test
	@rm -rf task_procebar_test