// RUN: %clang_cc1 -D__ARM_FEATURE_SVE -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s
// RUN: %clang_cc1 -D__ARM_FEATURE_SVE -DSVE_OVERLOADED_FORMS -triple aarch64-none-linux-gnu -target-feature +sve -fallow-half-arguments-and-returns -S -O1 -Werror -Wall -emit-llvm -o - %s | FileCheck %s

#include <arm_sve.h>

#ifdef SVE_OVERLOADED_FORMS
// A simple used,unused... macro, long enough to represent any SVE builtin.
#define SVE_ACLE_FUNC(A1,A2_UNUSED,A3,A4_UNUSED) A1##A3
#else
#define SVE_ACLE_FUNC(A1,A2,A3,A4) A1##A2##A3##A4
#endif

svfloat16_t test_svmla_lane_f16(svfloat16_t op1, svfloat16_t op2, svfloat16_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f16
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.fmla.lane.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2, <vscale x 8 x half> %op3, i32 0)
  // CHECK: ret <vscale x 8 x half> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f16,,)(op1, op2, op3, 0);
}

svfloat16_t test_svmla_lane_f16_1(svfloat16_t op1, svfloat16_t op2, svfloat16_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f16_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 8 x half> @llvm.aarch64.sve.fmla.lane.nxv8f16(<vscale x 8 x half> %op1, <vscale x 8 x half> %op2, <vscale x 8 x half> %op3, i32 7)
  // CHECK: ret <vscale x 8 x half> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f16,,)(op1, op2, op3, 7);
}

svfloat32_t test_svmla_lane_f32(svfloat32_t op1, svfloat32_t op2, svfloat32_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f32
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.fmla.lane.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2, <vscale x 4 x float> %op3, i32 0)
  // CHECK: ret <vscale x 4 x float> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f32,,)(op1, op2, op3, 0);
}

svfloat32_t test_svmla_lane_f32_1(svfloat32_t op1, svfloat32_t op2, svfloat32_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f32_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 4 x float> @llvm.aarch64.sve.fmla.lane.nxv4f32(<vscale x 4 x float> %op1, <vscale x 4 x float> %op2, <vscale x 4 x float> %op3, i32 3)
  // CHECK: ret <vscale x 4 x float> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f32,,)(op1, op2, op3, 3);
}

svfloat64_t test_svmla_lane_f64(svfloat64_t op1, svfloat64_t op2, svfloat64_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f64
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.fmla.lane.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2, <vscale x 2 x double> %op3, i32 0)
  // CHECK: ret <vscale x 2 x double> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f64,,)(op1, op2, op3, 0);
}

svfloat64_t test_svmla_lane_f64_1(svfloat64_t op1, svfloat64_t op2, svfloat64_t op3)
{
  // CHECK-LABEL: test_svmla_lane_f64_1
  // CHECK: %[[INTRINSIC:.*]] = call <vscale x 2 x double> @llvm.aarch64.sve.fmla.lane.nxv2f64(<vscale x 2 x double> %op1, <vscale x 2 x double> %op2, <vscale x 2 x double> %op3, i32 1)
  // CHECK: ret <vscale x 2 x double> %[[INTRINSIC]]
  return SVE_ACLE_FUNC(svmla_lane,_f64,,)(op1, op2, op3, 1);
}
