// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>

#include "single_layer_tests/embedding_bag_offsets_sum.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;

namespace {
const std::vector<InferenceEngine::Precision> netPrecisions = {
        InferenceEngine::Precision::FP32,
        InferenceEngine::Precision::FP16,
        InferenceEngine::Precision::I32,
        InferenceEngine::Precision::I16,
        InferenceEngine::Precision::U8
};

const std::vector<InferenceEngine::Precision> indPrecisions = {
        InferenceEngine::Precision::I64,
        InferenceEngine::Precision::I32
};

const std::vector<std::vector<size_t>> emb_table_shape = {{5, 6}, {10, 35}, {5, 4, 16}};
const std::vector<std::vector<size_t>> indices =
        {{0, 1, 2, 2, 3}, {4, 4, 3, 1, 0}, {1, 2, 1, 2, 1, 2, 1, 2, 1, 2}};
const std::vector<std::vector<size_t>> offsets = {{0, 2}, {0, 0, 2, 2}, {2, 4}};
const std::vector<size_t> default_index = {0, 4};
const std::vector<bool> with_weights = {false, true};
const std::vector<bool> with_default_index = {false, true};

const auto embBagOffsetSumArgSet = ::testing::Combine(
        ::testing::ValuesIn(emb_table_shape),
        ::testing::ValuesIn(indices),
        ::testing::ValuesIn(offsets),
        ::testing::ValuesIn(default_index),
        ::testing::ValuesIn(with_weights),
        ::testing::ValuesIn(with_default_index)
);

INSTANTIATE_TEST_CASE_P(smoke_EmbeddingBagOffsetsSum, EmbeddingBagOffsetsSumLayerTest,
                        ::testing::Combine(
                                embBagOffsetSumArgSet,
                                ::testing::ValuesIn(netPrecisions),
                                ::testing::ValuesIn(indPrecisions),
                                ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                        EmbeddingBagOffsetsSumLayerTest::getTestCaseName);
}  // namespace