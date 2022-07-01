// Copyright (C) 2020 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "subgraph_tests/multiply_add.hpp"

using namespace SubgraphTestsDefinitions;

namespace {

const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16
};

const std::vector<std::vector<size_t>> inputShapes = {
        {2, 3},
        {2, 3, 4},
        {1, 3, 2, 2},
        {1, 3, 2, 2, 6},
};

INSTANTIATE_TEST_CASE_P(smoke_Check, MultiplyAddLayerTest,
                        ::testing::Combine(
                                ::testing::ValuesIn(inputShapes),
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        MultiplyAddLayerTest::getTestCaseName);

}  // namespace
