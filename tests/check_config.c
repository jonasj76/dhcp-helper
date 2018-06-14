#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "conf.h"

START_TEST (test_config_read_ok)
{
	cfg_t cfg;
	int res;

	res = conf_read(&cfg, "../examples/simple.json");

	ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST (test_config_read_not_found)
{
	cfg_t cfg;
	int res;

	res = conf_read(&cfg, "unknown.json");

	ck_assert_int_eq(res, 1);
}
END_TEST

Suite* register_suite(void)
{
	Suite *s = suite_create("config");
	TCase *tc_config_read = tcase_create("config read");

	tcase_add_test(tc_config_read, test_config_read_ok);
	tcase_add_test(tc_config_read, test_config_read_not_found);
	suite_add_tcase(s, tc_config_read);

	return s;
}

int main(void)
{
	int number_failed;
	Suite *s = register_suite();
	SRunner *sr = srunner_create(s);

	srunner_run_all(sr, CK_VERBOSE);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
