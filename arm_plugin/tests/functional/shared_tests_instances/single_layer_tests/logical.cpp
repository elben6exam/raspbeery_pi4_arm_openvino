// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>
#include "single_layer_tests/logical.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;
using namespace LayerTestsDefinitions::LogicalParams;

namespace {

std::map<std::vector<size_t>, std::vector<std::vector<size_t >>> inputShapes = {
        {{5}, {{5}}},
        {{2, 200}, {{2, 200}}},
        {{1, 3, 20}, {{1, 3, 20}}},
        {{2, 17, 3, 4}, {{2, 17, 3, 4}}},
};

std::map<std::vector<size_t>, std::vector<std::vector<size_t >>> inputShapesNot = {
        {{1}, {}},
        {{5}, {}},
        {{2, 200}, {}},
        {{1, 3, 20}, {}},
        {{2, 17, 3, 4}, {}},
        {{2, 1, 1, 3, 1}, {}},
};

std::vector<ngraph::helpers::LogicalTypes> logicalOpTypes = {
        ngraph::helpers::LogicalTypes::LOGICAL_AND,
        ngraph::helpers::LogicalTypes::LOGICAL_OR,
        ngraph::helpers::LogicalTypes::LOGICAL_XOR,
};

std::vector<ngraph::helpers::InputLayerType> secondInputTypes = {
        ngraph::helpers::InputLayerType::CONSTANT,
        ngraph::helpers::InputLayerType::PARAMETER,
};

std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16,
};

std::map<std::string, std::string> additional_config = {};

const auto LogicalTestParams = ::testing::Combine(
        ::testing::ValuesIn(LogicalLayerTest::combineShapes(inputShapes)),
        ::testing::ValuesIn(logicalOpTypes),
        ::testing::ValuesIn(secondInputTypes),
        ::testing::ValuesIn(netPrecisions),
        ::testing::Values(InferenceEngine::Precision::BOOL),
        ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
        ::testing::Values(InferenceEngine::Layout::ANY),
        ::testing::Values(InferenceEngine::Layout::ANY),
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::Values(additional_config));

const auto LogicalTestParamsNot = ::testing::Combine(
        ::testing::ValuesIn(LogicalLayerTest::combineShapes(inputShapesNot)),
        ::testing::Values(ngraph::helpers::LogicalTypes::LOGICAL_NOT),
        ::testing::Values(ngraph::helpers::InputLayerType::CONSTANT),
        ::testing::ValuesIn(netPrecisions),
        ::testing::Values(InferenceEngine::Precision::BOOL),
        ::testing::Values(InferenceEngine::Precision::UNSPECIFIED),
        ::testing::Values(InferenceEngine::Layout::ANY),
        ::testing::Values(InferenceEngine::Layout::ANY),
        ::testing::Values(CommonTestUtils::DEVICE_CPU),
        ::testing::Values(additional_config));

INSTANTIATE_TEST_CASE_P(smoke_BinaryLogical, LogicalLayerTest, LogicalTestParams, LogicalLayerTest::getTestCaseName);

INSTANTIATE_TEST_CASE_P(smoke_LogicalNot, LogicalLayerTest, LogicalTestParamsNot, LogicalLayerTest::getTestCaseName);
}  // namespace
