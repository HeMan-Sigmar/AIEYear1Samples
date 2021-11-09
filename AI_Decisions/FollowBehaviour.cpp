#include "FollowBehaviour.h"
#include "Agent.h"
#include "NodeMap.h"
#include "raymath.h"

namespace pathfinding
{
    void FollowBehaviour::Update(Agent* agent, float deltaTime)
    {
        // check if the agent has moved significantly from its last position
        // if so we want to repath towards it
        Agent* target = agent->GetTarget();

        float dist = Vector2Distance(target->GetPosition(), lastTargetPosition);
        if (dist > agent->GetNodeMap()->cellSize)
        {
            lastTargetPosition = target->GetPosition();
            agent->GoTo(lastTargetPosition);
        }
    }
}
