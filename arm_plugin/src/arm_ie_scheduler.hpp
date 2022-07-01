// Copyright (C) 2020-2022 Intel Corporation
// SPDX-License-Identifier: Apache-2.0
//

#pragma once

#include <arm_compute/runtime/Scheduler.h>
#include <arm_compute/core/CPP/ICPPKernel.h>
#include <arm_compute/core/ITensorPack.h>

namespace ArmPlugin {
struct IEScheduler final : public arm_compute::IScheduler {
    IEScheduler();
    ~IEScheduler() override;
    void set_num_threads(unsigned int num_threads) override;
    std::uint32_t num_threads() const override;
    void Schedule(arm_compute::ICPPKernel*               kernel,
                  const arm_compute::IScheduler::Hints&  hints,
                  const arm_compute::Window&             max_window,
                  arm_compute::ITensorPack&              tensors);
    void schedule(arm_compute::ICPPKernel* kernel, const arm_compute::IScheduler::Hints& hints) override;
    void schedule_op(arm_compute::ICPPKernel*               kernel,
                     const arm_compute::IScheduler::Hints&  hints,
                     const arm_compute::Window&             window,
                     arm_compute::ITensorPack&              tensors) override;
    void run_workloads(std::vector<arm_compute::IScheduler::Workload>& workloads) override;
};
}  //  namespace ArmPlugin
