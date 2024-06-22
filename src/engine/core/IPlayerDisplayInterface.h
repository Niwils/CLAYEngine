#ifndef _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H
#define _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H

#include <Types.h>
#include <IOverlayInterface.h>

class IPlayerDisplayInterface
{
public:
    IPlayerDisplayInterface();

    ~IPlayerDisplayInterface();

    virtual void createOverlay(IOverlayInterface *_pDisplay) = 0;
    virtual void removeOverlay(s_uuid _uuid) = 0;
};

#endif /** End of _ENGINE_CORE_IPLAYERDISPLAYINTERFACE_H */