#include "minunit.h"
#include "philosophers.h"

int tests_run = 0;

static char *test_valid_args() {
    char *args[] = {"./philo", "5", "800", "200", "200"};
    MU_ASSERT("Error: valid arguments should return false", ft_validate_args(5, args) == false);
    return 0;
}

static char *test_too_few_args() {
    char *args[] = {"./philo", "5", "800"};
    MU_ASSERT("Error: too few arguments should return true", ft_validate_args(3, args) == true);
    return 0;
}

static char *test_invalid_args() {
    char *args[] = {"./philo", "5", "800", "abc", "200"};
    MU_ASSERT("Error: invalid arguments should return true", ft_validate_args(5, args) == true);
    return 0;
}

static char *all_tests() {
    MU_RUN_TEST(test_valid_args);
    MU_RUN_TEST(test_too_few_args);
    MU_RUN_TEST(test_invalid_args);
    return 0;
}

int main() {
    char *result = all_tests();
    if (result != 0) {
        printf("%s\n", result);
    } else {
        printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
}