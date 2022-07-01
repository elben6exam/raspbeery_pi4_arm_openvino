// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
#include <subgraph_tests/get_output_before_activation.hpp>
#include "common_test_utils/test_constants.hpp"

namespace SubgraphTestsDefinitions {
namespace {
    std::vector<size_t> input_sizes = {
        80,
        32,
        64,
        100
    };

    std::vector<midOutputType> midLayerTypes {
        midOutputType::Mul,
        midOutputType::Sub,
        midOutputType::Sum
    };

    std::map<std::string, std::string> additional_config = {};
} // namespace

const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16
};


INSTANTIATE_TEST_CASE_P(smoke_Check, OutputBeforeActivation,
    ::testing::Combine(
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::ValuesIn(netPrecisions),
        ::testing::ValuesIn(input_sizes),
        ::testing::ValuesIn(midLayerTypes),
        ::testing::Values(additional_config)),
    OutputBeforeActivation::getTestCaseName);
} // namespace SubgraphTestsDefinitions
