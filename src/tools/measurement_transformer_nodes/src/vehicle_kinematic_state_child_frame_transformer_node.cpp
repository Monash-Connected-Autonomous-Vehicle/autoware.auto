// Copyright 2021 The Autoware Foundation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "measurement_transformer_nodes/vehicle_kinematic_state_child_frame_transformer_node.hpp"
#include <autoware_auto_msgs/msg/vehicle_kinematic_state.hpp>
#include <motion_common/motion_common.hpp>

namespace autoware
{
namespace measurement_transformer_nodes
{

using autoware::common::types::float32_t;

VehicleKinematicStateChildFrameTransformerNode::VehicleKinematicStateChildFrameTransformerNode(
  const rclcpp::NodeOptions & options)
: ChildFrameTransformerNode<VehicleKinematicState>(
    "vehicle_kinematic_state_child_frame_transformer",
    "vks_in",
    "vks_out",
    options)
{
}

VehicleKinematicState VehicleKinematicStateChildFrameTransformerNode::transform_to_measurement(
  const TransformStamped & tf)
{
  VehicleKinematicState vks;
  vks.state.x = static_cast<float32_t>(tf.transform.translation.x);
  vks.state.y = static_cast<float32_t>(tf.transform.translation.y);
  vks.state.heading.imag = static_cast<float32_t>(tf.transform.rotation.z);
  vks.state.heading.real = static_cast<float32_t>(tf.transform.rotation.w);
  return vks;
}

TransformStamped VehicleKinematicStateChildFrameTransformerNode::measurement_to_transform(
  const VehicleKinematicState & measurement)
{
  TransformStamped tf;
  tf.transform.translation.x = measurement.state.x;
  tf.transform.translation.y = measurement.state.y;
  tf.transform.rotation.z = measurement.state.heading.imag;
  tf.transform.rotation.w = measurement.state.heading.real;
  return tf;
}

void VehicleKinematicStateChildFrameTransformerNode::apply_transform(
  const VehicleKinematicState & measurement_in,
  VehicleKinematicState & measurement_out,
  const TransformStamped & tf)
{
  motion::motion_common::doTransform(measurement_in, measurement_out, tf);
}

}  // namespace measurement_transformer_nodes
}  // namespace autoware

#include "rclcpp_components/register_node_macro.hpp"

// This acts as an entry point, allowing the component to be
// discoverable when its library is being loaded into a running process
RCLCPP_COMPONENTS_REGISTER_NODE(
  autoware::measurement_transformer_nodes::VehicleKinematicStateChildFrameTransformerNode)
