#include "common.h"

namespace bpftrace {
namespace test {
namespace codegen {

TEST(codegen, count_cast)
{
  test("kprobe:f { @x = count(); if (@x > 5) { print((6)); } }", NAME);
}

TEST(codegen, sum_cast)
{
  test("kprobe:f { @x = sum(2); if (@x > 5) { print((6)); } }", NAME);
}

TEST(codegen, count_cast_loop)
{
  test(
      "kprobe:f { @x[1] = count(); for ($kv : @x) { print(($kv.0, $kv.1)); } }",
      NAME);
}

TEST(codegen, sum_cast_loop)
{
  test("kprobe:f { @x[1] = sum(2); for ($kv : @x) { print(($kv.0, $kv.1)); } }",
       NAME);
}

TEST(codegen, count_no_cast_for_print)
{
  test("BEGIN { @ = count(); print(@) }", NAME);
}

} // namespace codegen
} // namespace test
} // namespace bpftrace
