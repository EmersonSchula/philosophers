#include "minunit.h"
#include "philosophers.h"

int tests_run = 0;

// Função auxiliar para resetar o estado global
void reset_rules() {
    t_rules *rules = get_rules();
    rules->philo_dead = false;
    rules->num_of_philosophers = 0;
    rules->die_time = 0;
    rules->eat_time = 0;
    rules->sleep_time = 0;
    rules->think_time = 0;
    rules->num_of_meals = 0;
    rules->philo = NULL;
}

// -------------------- Testes para init_rules --------------------
static char *test_valid_args() {
    char *args[] = {"./philo", "5", "800", "200", "200"};
    reset_rules();
    t_rules *rules = get_rules();

    MU_ASSERT("Error: init_rules should return false for valid arguments", init_rules(5, args) == false);
    MU_ASSERT("Error: number of philosophers not set correctly", rules->num_of_philosophers == 5);
    MU_ASSERT("Error: die_time not set correctly", rules->die_time == 800);
    MU_ASSERT("Error: eat_time not set correctly", rules->eat_time == 200);
    MU_ASSERT("Error: sleep_time not set correctly", rules->sleep_time == 200);
    MU_ASSERT("Error: think_time not calculated correctly", rules->think_time == 5);
    return 0;
}

static char *test_invalid_philosopher_count() {
    char *args[] = {"./philo", "0", "800", "200", "200"};
    reset_rules();

    MU_ASSERT("Error: init_rules should return true for invalid philosopher count", init_rules(5, args) == true);
    return 0;
}

// -------------------- Testes para thread_build --------------------
static char *test_thread_build() {
    t_thread thread;
    t_philo philo;

    thread_build(&thread, &philo);
    MU_ASSERT("Error: thread function not set correctly", thread.fun == &philo_task);
    MU_ASSERT("Error: thread args not set correctly", thread.args == &philo);
    return 0;
}

// -------------------- Testes para ft_validate_args --------------------
static char *test_validate_args_valid() {
    char *args[] = {"./philo", "5", "800", "200", "200"};
    MU_ASSERT("Error: ft_validate_args should return false for valid arguments", ft_validate_args(5, args) == false);
    return 0;
}

static char *test_validate_args_invalid() {
    char *args[] = {"./philo", "5", "800", "abc", "200"};
    MU_ASSERT("Error: ft_validate_args should return true for invalid arguments", ft_validate_args(5, args) == true);
    return 0;
}

// -------------------- Testes para check_philo_dead --------------------
static char *test_check_philo_dead() {
    reset_rules();
    t_rules *rules = get_rules();
    rules->philo_dead = true;

    MU_ASSERT("Error: check_philo_dead should return true when philo_dead is true", check_philo_dead() == true);

    rules->philo_dead = false;
    MU_ASSERT("Error: check_philo_dead should return false when philo_dead is false", check_philo_dead() == false);
    return 0;
}

// -------------------- Testes para ft_all_eaten --------------------
static char *test_all_eaten() {
    reset_rules();
    t_rules *rules = get_rules();
    rules->finish = true;

    MU_ASSERT("Error: ft_all_eaten should return true when finish is true", ft_all_eaten() == true);

    rules->finish = false;
    MU_ASSERT("Error: ft_all_eaten should return false when finish is false", ft_all_eaten() == false);
    return 0;
}

// -------------------- Função para rodar todos os testes --------------------
static char *all_tests() {
    // Testes de init_rules
    MU_RUN_TEST(test_valid_args);
    MU_RUN_TEST(test_invalid_philosopher_count);

    // Testes de thread_build
    MU_RUN_TEST(test_thread_build);

    // Testes de ft_validate_args
    MU_RUN_TEST(test_validate_args_valid);
    MU_RUN_TEST(test_validate_args_invalid);

    // Testes de check_philo_dead
    MU_RUN_TEST(test_check_philo_dead);

    // Testes de ft_all_eaten
    MU_RUN_TEST(test_all_eaten);

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