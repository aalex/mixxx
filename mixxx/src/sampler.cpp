#include "sampler.h"
#include "engine/enginebuffer.h"
#include "engine/enginedeck.h"
#include "engine/enginemaster.h"

Sampler::Sampler(QObject* pParent,
                 ConfigObject<ConfigValue>* pConfig,
                 EngineMaster* pMixingEngine,
                 EngineChannel::ChannelOrientation defaultOrientation,
                 QString group)
        : BaseTrackPlayer(pParent, pConfig, pMixingEngine, defaultOrientation, NULL, group) {

    const char* pSafeGroupName = strdup(getGroup().toAscii().constData());

    EngineDeck* pChannel = new EngineDeck(pSafeGroupName,
                                        pConfig, defaultOrientation);
    EngineBuffer* pEngineBuffer = pChannel->getEngineBuffer();
    pMixingEngine->addChannel(pChannel);
    initiate(pEngineBuffer,pSafeGroupName,pConfig);
}

Sampler::~Sampler()
{
}
