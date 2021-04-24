/*
 * Copyright (c) 2021, The Linux Foundation. All rights reserved.
 * Not a Contribution
 */
/*
 * Copyright (C) 2020 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <aidl/android/hardware/gnss/BnGnssPowerIndication.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

using ::aidl::android::hardware::gnss::BnGnssPowerIndication;
using ::aidl::android::hardware::gnss::IGnssPowerIndicationCallback;

struct GnssPowerIndication : public BnGnssPowerIndication {
public:
    ::ndk::ScopedAStatus setCallback(
            const std::shared_ptr<IGnssPowerIndicationCallback>& in_callback) override;
    ::ndk::ScopedAStatus requestGnssPowerStats() override { return ndk::ScopedAStatus::ok(); }

    void cleanup();
private:
    std::shared_ptr<IGnssPowerIndicationCallback> mGnssPowerIndicationCb = nullptr;
};

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
