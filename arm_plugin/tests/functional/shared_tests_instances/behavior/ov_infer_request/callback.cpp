// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "behavior/ov_infer_request/callback.hpp"

using namespace ov::test::behavior;

namespace {
const std::vector<ov::AnyMap> configs = {
        {},
        {ov::streams::num(ov::streams::AUTO)},
        {ov::streams::num(0), ov::inference_num_threads(1)}
};

const std::vector<ov::AnyMap> multiConfigs = {
        {{ MULTI_CONFIG_KEY(DEVICE_PRIORITIES) , CommonTestUtils::DEVICE_CPU}}
};

INSTANTIATE_TEST_SUITE_P(smoke_BehaviorTests, OVInferRequestCallbackTests,
        ::testing::Combine(
            ::testing::Values(CommonTestUtils::DEVICE_CPU),
            ::testing::ValuesIn(configs)),
        OVInferRequestCallbackTests::getTestCaseName);

INSTANTIATE_TEST_SUITE_P(smoke_Multi_BehaviorTests, OVInferRequestCallbackTests,
        ::testing::Combine(
                ::testing::Values(CommonTestUtils::DEVICE_MULTI),
                ::testing::ValuesIn(multiConfigs)),
        OVInferRequestCallbackTests::getTestCaseName);

INSTANTIATE_TEST_SUITE_P(smoke_Auto_BehaviorTests, OVInferRequestCallbackTests,
        ::testing::Combine(
                ::testing::Values(CommonTestUtils::DEVICE_AUTO),
                ::testing::ValuesIn(multiConfigs)),
        OVInferRequestCallbackTests::getTestCaseName);
}  // namespace
