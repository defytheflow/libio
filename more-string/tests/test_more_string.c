#include <more-string.h>

#include <stdlib.h>

#include <check.h>

START_TEST(test_strrev)
{
        char original[] = "hermione";
        char reversed[sizeof(original)];

        strrev(reversed, original);

        ck_assert_str_eq(reversed, "enoimreh");
}
END_TEST

Suite* more_string_suite(void)
{
        Suite* s;
        TCase* tc_core;

        s = suite_create("more-string");
        tc_core = tcase_create("core");

        tcase_add_test(tc_core, test_strrev);
        suite_add_tcase(s, tc_core);

        return s;
}

int main(void)
{
        int no_failed = 0;
        Suite* s;
        SRunner* runner;

        s = more_string_suite();
        runner = srunner_create(s);

        srunner_run_all(runner, CK_NORMAL);
        no_failed = srunner_ntests_failed(runner);
        srunner_free(runner);

        return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
