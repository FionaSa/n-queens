#include <stdint.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <cmocka.h>

#include "queens.c"

static void test_same_diagonal(void **state) {
  //Test with queens not in the same diagonal
  assert_false(check_same_diagonal(0,0,2,1));
  //in the middle of the board
  assert_false(check_same_diagonal(2,2,3,0));
  //one at the begin, one at the end
  assert_false(check_same_diagonal(0,3,4,0));

  //Test with the queens on the same diagonals
  assert_true(check_same_diagonal(0,0,1,1));
  //in the middle of the board
  assert_true(check_same_diagonal(3,2,4,3));
  //one at the begin, one at the end
  assert_true(check_same_diagonal(0,0,4,4));
  // a little shifted (not on the main diagonal)
  assert_true(check_same_diagonal(0,1,3,4));

}
static void test_check_column_ok(void **state) {

  //Test with queens ok
  assert_true(check_column_ok(3,2,(int[4]){1,3,0,-1}));

  assert_true(check_column_ok(0,1,(int[4]){0,3,2,3}));

  //same test as the function before 
  assert_true(check_column_ok(2,1,(int[5]){0,3,-1,-1,-1}));
  assert_true(check_column_ok(3,0,(int[4]){1,4,2,-1}));
  assert_true(check_column_ok(4,0,(int[5]){3,2,4,2,-1}));

  assert_false(check_column_ok(1,1,(int[2]){0,-1}));
  assert_false(check_column_ok(4,3,(int[5]){1,3,0,2,-1}));
  //This test is not correct(with the n queen problem) even before the one we test
  assert_false(check_column_ok(4,4,(int[4]){0,2,1,-1}));
  //This one neither
  assert_false(check_column_ok(3,4,(int[5]){1,3,0,-1,-1}));
}

static void test_find_available(void **state) {
  //not available higher than min 
  assert_int_equal(-1,find_available(2,5,(bool[5]){true,true,true,false,false}));

  //not available

  assert_int_equal(-1,find_available(0,5,(bool[5]){false,false,false,false,false}));

  //available
  assert_int_equal(3,find_available(2,5,(bool[5]){true,true,true,true,false}));

}

static void test__find_solution(void **state)
 {
  assert_true(_find_solution(5,2,(int[5]){2,0,0,0,0},(bool[5]){false,true,false,true,true}));

  assert_true(_find_solution(5,3,(int[5]){1,3,0,0,0},(bool[5]){true,false,true,false,true}));

   assert_false(_find_solution(4,2,(int[4]){0,2,-1,-1},(bool[4]){false,true,false,true}));

   assert_true(_find_solution(4,3,(int[4]){1,3,0,-1},(bool[4]){false,false,true,false}));
 }
static void test_find_solution(void **state)
{
  assert_false(find_solution(2,(int[2]){-1,-1})); 
  assert_false(find_solution(3,(int[3]){-1,-1,-1}));
  assert_true(find_solution(4,(int[4]){-1,-1,-1,-1}));
  assert_true(find_solution(5,(int[5]){-1,-1,-1,-1,-1}));
  assert_true(find_solution(10,calloc(10,sizeof(int))));
  assert_true(find_solution(20,calloc(20,sizeof(int))));
  assert_true(find_solution(30,calloc(30,sizeof(int))));


}

int main(void) {
  int result = 0;
  const struct CMUnitTest tests[] = {
      cmocka_unit_test(test_same_diagonal),
      cmocka_unit_test(test_check_column_ok),    
      cmocka_unit_test(test_find_available),
       cmocka_unit_test(test__find_solution),
       cmocka_unit_test(test_find_solution),
    

  };
  result |= cmocka_run_group_tests_name("queens", tests, NULL, NULL);

  return result;
}
