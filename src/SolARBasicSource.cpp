/**
 * @copyright Copyright (c) 2017 B-com http://www.b-com.com/
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
 */

#include "SolARBasicSource.h"
#include "core/Log.h"
namespace xpcf = org::bcom::xpcf;


XPCF_DEFINE_FACTORY_CREATE_INSTANCE(SolAR::MODULES::TOOLS::SolARBasicSource)

namespace SolAR {
using namespace datastructure;
using namespace api::source;
namespace MODULES {
namespace TOOLS {


SolARBasicSource::SolARBasicSource():ConfigurableBase(xpcf::toUUID<ISourceImage>())
{
   addInterface<api::source::ISourceImage>(this);
   m_image = nullptr;
   m_newImage = false;
}

SourceReturnCode SolARBasicSource::setInputTexture( void* sourceTexturehandle, int width, int height)
{
    m_mutex.lock();
    m_image = xpcf::utils::make_shared<Image>((unsigned char*)sourceTexturehandle, width, height, SolAR::Image::LAYOUT_RGB, SolAR::Image::INTERLEAVED, SolAR::Image::TYPE_8U);
    m_newImage = true;
    m_mutex.unlock();
    return SourceReturnCode::_NEW_IMAGE;
}

SourceReturnCode SolARBasicSource::getNextImage(SRef<Image> & image)
{
    m_mutex.lock();
    image = m_image->copy();
    m_mutex.unlock();
    return SourceReturnCode::_NEW_IMAGE;
}

}
}
}