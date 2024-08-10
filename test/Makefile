all_test:
	make common_procebar_test

# 测试common_procebar
common_procebar_test:
	@echo "common_procebar_test"
	@gcc -o common_procebar_test common_procebar_test.c ../lib/procebar/procebar.c ../lib/procebar/procebar_style/common_procebar.c -I ../lib/procebar -I ../lib/procebar/procebar_style
	@./common_procebar_test
	@rm -rf common_procebar_test