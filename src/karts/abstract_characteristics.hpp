//
//  SuperTuxKart - a fun racing game with go-kart
//  Copyright (C) 2006-2015 SuperTuxKart-Team
//
//  This program is free software; you can redistribute it and/or
//  modify it under the terms of the GNU General Public License
//  as published by the Free Software Foundation; either version 3
//  of the License, or (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

#ifndef HEADER_ABSTRACT_CHARACTERISTICS_HPP
#define HEADER_ABSTRACT_CHARACTERISTICS_HPP

#include "utils/interpolation_array.hpp"
#include "utils/vec3.hpp"

#include <vector>

class SkiddingProperties;

/**
 * Characteristics are the properties of a kart that influence
 * gameplay mechanics.
 * The biggest parts are:
 * - Physics
 * - Visuals
 * - Items
 * - and miscellaneous properties like nitro and startup boost.
 *
 * The documentation of these properties can be found in
 * the kart_characteristics.xml file.
 */
class AbstractCharacteristics
{
private:
    /* Characteristics that are saved as float. Use the following lines as input 
    Suspension: stiffness, rest, travelCm, expSpringResponse, maxForce
    Stability: rollInfluence, chassisLinearDamping, chassisAngularDamping, downwardImpulseFactor, trackConnectionAccel, smoothFlyingImpulse
    Turn: timeResetSteer
    Engine: power, maxSpeed, brakeFactor, brakeTimeIncrease, maxSpeedReverseRatio
    Mass
    Wheels: dampingRelaxation, dampingCompression, wheelRadius
    Camera: distance, forwardUpAngle, backwardUpAngle
    Jump: animationTime
    Lean: max, speed
    Anvil: duration, weight, speedFactor
    Parachute: friction, duration, durationOther, lboundFranction, uboundFranction, maxSpeed
    Bubblegum: duration, speedFraction, torque, fadeInTime, shieldDuration
    Zipper: duration, force, speedGain, speedIncrease, fadeOutTime
    Swatter: duration, distance, squashDuration, squashSlowdown
    Plunger: maxLength, force, duration, speedIncrease, fadeOutTime, inFaceTime
    Rescue: duration, vertOffset, height
    Explosion: duration, radius, invulnerabilityTime
    Nitro: duration, engineForce, consumption, smallContainer, bigContainer, maxSpeedIncrease, fadeOutTime, max
    Slipstream: duration, length, width, collectTime, useTime, addPower, minSpeed, maxSpeedIncrease, fadeOutTime
    */

    /* ---------- Variables generated by the script ---------- */

    // Suspension
    float m_suspension_stiffness;
    float m_suspension_rest;
    float m_suspension_travel_cm;
    float m_suspension_exp_spring_response;
    float m_suspension_max_force;

    // Stability
    float m_stability_roll_influence;
    float m_stability_chassis_linear_damping;
    float m_stability_chassis_angular_damping;
    float m_stability_downward_impulse_factor;
    float m_stability_track_connection_accel;
    float m_stability_smooth_flying_impulse;

    // Turn
    float m_turn_time_reset_steer;

    // Engine
    float m_engine_power;
    float m_engine_max_speed;
    float m_engine_brake_factor;
    float m_engine_brake_time_increase;
    float m_engine_max_speed_reverse_ratio;

    // Mass
    float m_mass;

    // Wheels
    float m_wheels_damping_relaxation;
    float m_wheels_damping_compression;
    float m_wheels_wheel_radius;

    // Camera
    float m_camera_distance;
    float m_camera_forward_up_angle;
    float m_camera_backward_up_angle;

    // Jump
    float m_jump_animation_time;

    // Lean
    float m_lean_max;
    float m_lean_speed;

    // Anvil
    float m_anvil_duration;
    float m_anvil_weight;
    float m_anvil_speed_factor;

    // Parachute
    float m_parachute_friction;
    float m_parachute_duration;
    float m_parachute_duration_other;
    float m_parachute_lbound_franction;
    float m_parachute_ubound_franction;
    float m_parachute_max_speed;

    // Bubblegum
    float m_bubblegum_duration;
    float m_bubblegum_speed_fraction;
    float m_bubblegum_torque;
    float m_bubblegum_fade_in_time;
    float m_bubblegum_shield_duration;

    // Zipper
    float m_zipper_duration;
    float m_zipper_force;
    float m_zipper_speed_gain;
    float m_zipper_speed_increase;
    float m_zipper_fade_out_time;

    // Swatter
    float m_swatter_duration;
    float m_swatter_distance;
    float m_swatter_squash_duration;
    float m_swatter_squash_slowdown;

    // Plunger
    float m_plunger_max_length;
    float m_plunger_force;
    float m_plunger_duration;
    float m_plunger_speed_increase;
    float m_plunger_fade_out_time;
    float m_plunger_in_face_time;

    // Rescue
    float m_rescue_duration;
    float m_rescue_vert_offset;
    float m_rescue_height;

    // Explosion
    float m_explosion_duration;
    float m_explosion_radius;
    float m_explosion_invulnerability_time;

    // Nitro
    float m_nitro_duration;
    float m_nitro_engine_force;
    float m_nitro_consumption;
    float m_nitro_small_container;
    float m_nitro_big_container;
    float m_nitro_max_speed_increase;
    float m_nitro_fade_out_time;
    float m_nitro_max;

    // Slipstream
    float m_slipstream_duration;
    float m_slipstream_length;
    float m_slipstream_width;
    float m_slipstream_collect_time;
    float m_slipstream_use_time;
    float m_slipstream_add_power;
    float m_slipstream_min_speed;
    float m_slipstream_max_speed_increase;
    float m_slipstream_fade_out_time;

    /* ---------- Variables added by hand ---------- */

    // Turn
    InterpolationArray m_turn_radius;
    InterpolationArray m_turn_time_full_steer;

    // Gear
    std::vector<float> m_gear_switch_ratio;
    std::vector<float> m_gear_power_increase;

    // Wheels
    std::vector<Vec3> m_wheel_position;

    // Skid
    SkiddingProperties *m_skidding;


    /* ---------- Miscellaneous ---------- */

    // Startup
    std::vector<float> m_startup_time;
    std::vector<float> m_startup_boost;

public:
    AbstractCharacteristics();

    /* ---------- Getters generated by the script ---------- */

    float getSuspensionStiffness()            const { return m_suspension_stiffness;              }
    float getSuspensionRest()                 const { return m_suspension_rest;                   }
    float getSuspensionTravelCm()             const { return m_suspension_travel_cm;              }
    float getSuspensionExpSpringResponse()    const { return m_suspension_exp_spring_response;    }
    float getSuspensionMaxForce()             const { return m_suspension_max_force;              }

    float getStabilityRollInfluence()         const { return m_stability_roll_influence;          }
    float getStabilityChassisLinearDamping()  const { return m_stability_chassis_linear_damping;  }
    float getStabilityChassisAngularDamping() const { return m_stability_chassis_angular_damping; }
    float getStabilityDownwardImpulseFactor() const { return m_stability_downward_impulse_factor; }
    float getStabilityTrackConnectionAccel()  const { return m_stability_track_connection_accel;  }
    float getStabilitySmoothFlyingImpulse()   const { return m_stability_smooth_flying_impulse;   }

    float getTurnTimeResetSteer()             const { return m_turn_time_reset_steer;             }

    float getEnginePower()                    const { return m_engine_power;                      }
    float getEngineMaxSpeed()                 const { return m_engine_max_speed;                  }
    float getEngineBrakeFactor()              const { return m_engine_brake_factor;               }
    float getEngineBrakeTimeIncrease()        const { return m_engine_brake_time_increase;        }
    float getEngineMaxSpeedReverseRatio()     const { return m_engine_max_speed_reverse_ratio;    }

    float getMass()                           const { return m_mass;                              }

    float getWheelsDampingRelaxation()        const { return m_wheels_damping_relaxation;         }
    float getWheelsDampingCompression()       const { return m_wheels_damping_compression;        }
    float getWheelsWheelRadius()              const { return m_wheels_wheel_radius;               }

    float getCameraDistance()                 const { return m_camera_distance;                   }
    float getCameraForwardUpAngle()           const { return m_camera_forward_up_angle;           }
    float getCameraBackwardUpAngle()          const { return m_camera_backward_up_angle;          }

    float getJumpAnimationTime()              const { return m_jump_animation_time;               }

    float getLeanMax()                        const { return m_lean_max;                          }
    float getLeanSpeed()                      const { return m_lean_speed;                        }

    float getAnvilDuration()                  const { return m_anvil_duration;                    }
    float getAnvilWeight()                    const { return m_anvil_weight;                      }
    float getAnvilSpeedFactor()               const { return m_anvil_speed_factor;                }

    float getParachuteFriction()              const { return m_parachute_friction;                }
    float getParachuteDuration()              const { return m_parachute_duration;                }
    float getParachuteDurationOther()         const { return m_parachute_duration_other;          }
    float getParachuteLboundFranction()       const { return m_parachute_lbound_franction;        }
    float getParachuteUboundFranction()       const { return m_parachute_ubound_franction;        }
    float getParachuteMaxSpeed()              const { return m_parachute_max_speed;               }

    float getBubblegumDuration()              const { return m_bubblegum_duration;                }
    float getBubblegumSpeedFraction()         const { return m_bubblegum_speed_fraction;          }
    float getBubblegumTorque()                const { return m_bubblegum_torque;                  }
    float getBubblegumFadeInTime()            const { return m_bubblegum_fade_in_time;            }
    float getBubblegumShieldDuration()        const { return m_bubblegum_shield_duration;         }

    float getZipperDuration()                 const { return m_zipper_duration;                   }
    float getZipperForce()                    const { return m_zipper_force;                      }
    float getZipperSpeedGain()                const { return m_zipper_speed_gain;                 }
    float getZipperSpeedIncrease()            const { return m_zipper_speed_increase;             }
    float getZipperFadeOutTime()              const { return m_zipper_fade_out_time;              }

    float getSwatterDuration()                const { return m_swatter_duration;                  }
    float getSwatterDistance()                const { return m_swatter_distance;                  }
    float getSwatterSquashDuration()          const { return m_swatter_squash_duration;           }
    float getSwatterSquashSlowdown()          const { return m_swatter_squash_slowdown;           }

    float getPlungerMaxLength()               const { return m_plunger_max_length;                }
    float getPlungerForce()                   const { return m_plunger_force;                     }
    float getPlungerDuration()                const { return m_plunger_duration;                  }
    float getPlungerSpeedIncrease()           const { return m_plunger_speed_increase;            }
    float getPlungerFadeOutTime()             const { return m_plunger_fade_out_time;             }
    float getPlungerInFaceTime()              const { return m_plunger_in_face_time;              }

    float getRescueDuration()                 const { return m_rescue_duration;                   }
    float getRescueVertOffset()               const { return m_rescue_vert_offset;                }
    float getRescueHeight()                   const { return m_rescue_height;                     }

    float getExplosionDuration()              const { return m_explosion_duration;                }
    float getExplosionRadius()                const { return m_explosion_radius;                  }
    float getExplosionInvulnerabilityTime()   const { return m_explosion_invulnerability_time;    }

    float getNitroDuration()                  const { return m_nitro_duration;                    }
    float getNitroEngineForce()               const { return m_nitro_engine_force;                }
    float getNitroConsumption()               const { return m_nitro_consumption;                 }
    float getNitroSmallContainer()            const { return m_nitro_small_container;             }
    float getNitroBigContainer()              const { return m_nitro_big_container;               }
    float getNitroMaxSpeedIncrease()          const { return m_nitro_max_speed_increase;          }
    float getNitroFadeOutTime()               const { return m_nitro_fade_out_time;               }
    float getNitroMax()                       const { return m_nitro_max;                         }

    float getSlipstreamDuration()             const { return m_slipstream_duration;               }
    float getSlipstreamLength()               const { return m_slipstream_length;                 }
    float getSlipstreamWidth()                const { return m_slipstream_width;                  }
    float getSlipstreamCollectTime()          const { return m_slipstream_collect_time;           }
    float getSlipstreamUseTime()              const { return m_slipstream_use_time;               }
    float getSlipstreamAddPower()             const { return m_slipstream_add_power;              }
    float getSlipstreamMinSpeed()             const { return m_slipstream_min_speed;              }
    float getSlipstreamMaxSpeedIncrease()     const { return m_slipstream_max_speed_increase;     }
    float getSlipstreamFadeOutTime()          const { return m_slipstream_fade_out_time;          }

    /* ---------- Getters added by hand ---------- */

    float getTurnRadius(float steer)          const { return m_turn_radius.get(steer);            }
    float getTurnTimeFullSteer(float steer)   const { return m_turn_time_full_steer.get(steer);   }

    float getGearSwitchRatio(int gear)        const { return m_gear_switch_ratio[gear];           }
    float getGearPowerIncrease(int gear)      const { return m_gear_power_increase[gear];         }

    Vec3 getWheelPosition(int wheel)          const { return m_wheel_position[wheel];             }

    SkiddingProperties* getSkiddingProperties() const { return m_skidding;                        }

protected:

    /* ---------- Setters generated by the script ---------- */

    void setSuspensionStiffness(float value)            { m_suspension_stiffness              = value; }
    void setSuspensionRest(float value)                 { m_suspension_rest                   = value; }
    void setSuspensionTravelCm(float value)             { m_suspension_travel_cm              = value; }
    void setSuspensionExpSpringResponse(float value)    { m_suspension_exp_spring_response    = value; }
    void setSuspensionMaxForce(float value)             { m_suspension_max_force              = value; }

    void setStabilityRollInfluence(float value)         { m_stability_roll_influence          = value; }
    void setStabilityChassisLinearDamping(float value)  { m_stability_chassis_linear_damping  = value; }
    void setStabilityChassisAngularDamping(float value) { m_stability_chassis_angular_damping = value; }
    void setStabilityDownwardImpulseFactor(float value) { m_stability_downward_impulse_factor = value; }
    void setStabilityTrackConnectionAccel(float value)  { m_stability_track_connection_accel  = value; }
    void setStabilitySmoothFlyingImpulse(float value)   { m_stability_smooth_flying_impulse   = value; }

    void setTurnTimeResetSteer(float value)             { m_turn_time_reset_steer             = value; }

    void setEnginePower(float value)                    { m_engine_power                      = value; }
    void setEngineMaxSpeed(float value)                 { m_engine_max_speed                  = value; }
    void setEngineBrakeFactor(float value)              { m_engine_brake_factor               = value; }
    void setEngineBrakeTimeIncrease(float value)        { m_engine_brake_time_increase        = value; }
    void setEngineMaxSpeedReverseRatio(float value)     { m_engine_max_speed_reverse_ratio    = value; }

    void setMass(float value)                           { m_mass                              = value; }

    void setWheelsDampingRelaxation(float value)        { m_wheels_damping_relaxation         = value; }
    void setWheelsDampingCompression(float value)       { m_wheels_damping_compression        = value; }
    void setWheelsWheelRadius(float value)              { m_wheels_wheel_radius               = value; }

    void setCameraDistance(float value)                 { m_camera_distance                   = value; }
    void setCameraForwardUpAngle(float value)           { m_camera_forward_up_angle           = value; }
    void setCameraBackwardUpAngle(float value)          { m_camera_backward_up_angle          = value; }

    void setJumpAnimationTime(float value)              { m_jump_animation_time               = value; }

    void setLeanMax(float value)                        { m_lean_max                          = value; }
    void setLeanSpeed(float value)                      { m_lean_speed                        = value; }

    void setAnvilDuration(float value)                  { m_anvil_duration                    = value; }
    void setAnvilWeight(float value)                    { m_anvil_weight                      = value; }
    void setAnvilSpeedFactor(float value)               { m_anvil_speed_factor                = value; }

    void setParachuteFriction(float value)              { m_parachute_friction                = value; }
    void setParachuteDuration(float value)              { m_parachute_duration                = value; }
    void setParachuteDurationOther(float value)         { m_parachute_duration_other          = value; }
    void setParachuteLboundFranction(float value)       { m_parachute_lbound_franction        = value; }
    void setParachuteUboundFranction(float value)       { m_parachute_ubound_franction        = value; }
    void setParachuteMaxSpeed(float value)              { m_parachute_max_speed               = value; }

    void setBubblegumDuration(float value)              { m_bubblegum_duration                = value; }
    void setBubblegumSpeedFraction(float value)         { m_bubblegum_speed_fraction          = value; }
    void setBubblegumTorque(float value)                { m_bubblegum_torque                  = value; }
    void setBubblegumFadeInTime(float value)            { m_bubblegum_fade_in_time            = value; }
    void setBubblegumShieldDuration(float value)        { m_bubblegum_shield_duration         = value; }

    void setZipperDuration(float value)                 { m_zipper_duration                   = value; }
    void setZipperForce(float value)                    { m_zipper_force                      = value; }
    void setZipperSpeedGain(float value)                { m_zipper_speed_gain                 = value; }
    void setZipperSpeedIncrease(float value)            { m_zipper_speed_increase             = value; }
    void setZipperFadeOutTime(float value)              { m_zipper_fade_out_time              = value; }

    void setSwatterDuration(float value)                { m_swatter_duration                  = value; }
    void setSwatterDistance(float value)                { m_swatter_distance                  = value; }
    void setSwatterSquashDuration(float value)          { m_swatter_squash_duration           = value; }
    void setSwatterSquashSlowdown(float value)          { m_swatter_squash_slowdown           = value; }

    void setPlungerMaxLength(float value)               { m_plunger_max_length                = value; }
    void setPlungerForce(float value)                   { m_plunger_force                     = value; }
    void setPlungerDuration(float value)                { m_plunger_duration                  = value; }
    void setPlungerSpeedIncrease(float value)           { m_plunger_speed_increase            = value; }
    void setPlungerFadeOutTime(float value)             { m_plunger_fade_out_time             = value; }
    void setPlungerInFaceTime(float value)              { m_plunger_in_face_time              = value; }

    void setRescueDuration(float value)                 { m_rescue_duration                   = value; }
    void setRescueVertOffset(float value)               { m_rescue_vert_offset                = value; }
    void setRescueHeight(float value)                   { m_rescue_height                     = value; }

    void setExplosionDuration(float value)              { m_explosion_duration                = value; }
    void setExplosionRadius(float value)                { m_explosion_radius                  = value; }
    void setExplosionInvulnerabilityTime(float value)   { m_explosion_invulnerability_time    = value; }

    void setNitroDuration(float value)                  { m_nitro_duration                    = value; }
    void setNitroEngineForce(float value)               { m_nitro_engine_force                = value; }
    void setNitroConsumption(float value)               { m_nitro_consumption                 = value; }
    void setNitroSmallContainer(float value)            { m_nitro_small_container             = value; }
    void setNitroBigContainer(float value)              { m_nitro_big_container               = value; }
    void setNitroMaxSpeedIncrease(float value)          { m_nitro_max_speed_increase          = value; }
    void setNitroFadeOutTime(float value)               { m_nitro_fade_out_time               = value; }
    void setNitroMax(float value)                       { m_nitro_max                         = value; }

    void setSlipstreamDuration(float value)             { m_slipstream_duration               = value; }
    void setSlipstreamLength(float value)               { m_slipstream_length                 = value; }
    void setSlipstreamWidth(float value)                { m_slipstream_width                  = value; }
    void setSlipstreamCollectTime(float value)          { m_slipstream_collect_time           = value; }
    void setSlipstreamUseTime(float value)              { m_slipstream_use_time               = value; }
    void setSlipstreamAddPower(float value)             { m_slipstream_add_power              = value; }
    void setSlipstreamMinSpeed(float value)             { m_slipstream_min_speed              = value; }
    void setSlipstreamMaxSpeedIncrease(float value)     { m_slipstream_max_speed_increase     = value; }
    void setSlipstreamFadeOutTime(float value)          { m_slipstream_fade_out_time          = value; }

    /* ---------- Setters added by hand ---------- */

    void setGearSwitchRatio(int gear, float value)   { m_gear_switch_ratio[gear]   = value; }
    void setGearPowerIncrease(int gear, float value) { m_gear_power_increase[gear] = value; }

    void setWheelPosition(int wheel, Vec3 value)     { m_wheel_position[wheel]     = value; }
    
};

#endif
