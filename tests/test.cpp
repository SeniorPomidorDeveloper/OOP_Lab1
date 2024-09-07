#include "./class_tests/class_tests.cpp"
#include "./export_tests/export_tests.cpp"

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  
  return RUN_ALL_TESTS();
}