// Copyright (C) 2018-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#include <vector>
#include <ngraph/op/util/attr_types.hpp>
#include "single_layer_tests/lstm_sequence.hpp"
#include "common_test_utils/test_constants.hpp"

using namespace LayerTestsDefinitions;

namespace {
    std::vector<ngraph::helpers::SequenceTestsMode> mode{ngraph::helpers::SequenceTestsMode::CONVERT_TO_TI_MAX_SEQ_LEN_CONST,
                                                         ngraph::helpers::SequenceTestsMode::CONVERT_TO_TI_RAND_SEQ_LEN_CONST,
                                                         ngraph::helpers::SequenceTestsMode::CONVERT_TO_TI_RAND_SEQ_LEN_PARAM,
                                                         ngraph::helpers::SequenceTestsMode::PURE_SEQ,
                                                         ngraph::helpers::SequenceTestsMode::PURE_SEQ_RAND_SEQ_LEN_CONST,
                                                         ngraph::helpers::SequenceTestsMode::PURE_SEQ_RAND_SEQ_LEN_PARAM};
    // output values increase rapidly without clip, so use only seq_lenghts = 2
    std::vector<size_t> seq_lengths_zero_clip{2};
    std::vector<size_t> seq_lengths_clip_non_zero{20};
    std::vector<size_t> batch{10};
    std::vector<size_t> hidden_size{1, 10};
    std::vector<size_t> input_size{10};
    std::vector<std::vector<std::string>> activations = {{"relu", "sigmoid", "tanh"}, {"sigmoid", "tanh", "tanh"},
                                                         {"tanh", "relu", "sigmoid"}, {"sigmoid", "sigmoid", "sigmoid"},
                                                         {"tanh", "tanh", "tanh"}, {"relu", "relu", "relu"}};
    std::vector<float> clip{0.f};
    std::vector<float> clip_non_zeros{0.7f};
    std::vector<ngraph::op::RecurrentSequenceDirection> direction = {ngraph::op::RecurrentSequenceDirection::FORWARD,
                                                           ngraph::op::RecurrentSequenceDirection::REVERSE,
                                                           ngraph::op::RecurrentSequenceDirection::BIDIRECTIONAL
    };
    std::vector<InferenceEngine::Precision> netPrecisions = {InferenceEngine::Precision::FP32,
                                                             InferenceEngine::Precision::FP16};

    INSTANTIATE_TEST_CASE_P(smoke_LSTMSequenceCommonZeroClip, LSTMSequenceTest,
                            ::testing::Combine(
                                    ::testing::ValuesIn(mode),
                                    ::testing::ValuesIn(seq_lengths_zero_clip),
                                    ::testing::ValuesIn(batch),
                                    ::testing::ValuesIn(hidden_size),
                                    ::testing::ValuesIn(input_size),
                                    ::testing::ValuesIn(activations),
                                    ::testing::ValuesIn(clip),
                                    ::testing::ValuesIn(direction),
                                    ::testing::ValuesIn(netPrecisions),
                                    ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                            LSTMSequenceTest::getTestCaseName);

    INSTANTIATE_TEST_CASE_P(smoke_LSTMSequenceCommonClip, LSTMSequenceTest,
                            ::testing::Combine(
                                    ::testing::ValuesIn(mode),
                                    ::testing::ValuesIn(seq_lengths_clip_non_zero),
                                    ::testing::ValuesIn(batch),
                                    ::testing::ValuesIn(hidden_size),
                                    ::testing::ValuesIn(input_size),
                                    ::testing::ValuesIn(activations),
                                    ::testing::ValuesIn(clip_non_zeros),
                                    ::testing::ValuesIn(direction),
                                    ::testing::ValuesIn(netPrecisions),
                                    ::testing::Values(CommonTestUtils::DEVICE_CPU)),
                            LSTMSequenceTest::getTestCaseName);

}  // namespace