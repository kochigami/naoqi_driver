/*
 * Copyright 2016 Aldebaran
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "speech_recognition.hpp"
#include "../helpers/driver_helpers.hpp"

namespace naoqi
{
namespace service
{

  SpeechRecognitionService::SpeechRecognitionService( const std::string& name, const std::string& topic, const bool& start_service, const qi::SessionPtr& session )
    : name_(name),
      topic_(topic),
      start_service_(start_service),
      session_(session)
  {}

  void SpeechRecognitionService::reset( ros::NodeHandle& nh )
  {
    service_ = nh.advertiseService(topic_, &SpeechRecognitionService::callback, this);
  }

  bool SpeechRecognitionService::callback( std_srvs::EmptyRequest& req, std_srvs::EmptyResponse& resp )
  {
    //resp.info = helpers::driver::getRobotInfo(session_);
    std::cout << "triggering speech recognition service" << std::endl;
    helpers::driver::startSpeechRecognition(session_);
    return true;
  }


}
}
