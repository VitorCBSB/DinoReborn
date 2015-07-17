/*
 * RenderUISystem.cpp
 *
 *  Created on: 23/12/2014
 *      Author: vitor
 */

#include "RenderUISystem.h"

RenderUISystem::RenderUISystem(WorldPtr world_ptr) : SingleEntitySystem(world_ptr) {
		add_aspect(
				new AllOfAspect<PositionComponent, UIComponent,
						AnimationComponent>());
		set_preprocess([&](std::vector<std::reference_wrapper<Entity>>& entities){
			std::sort(entities.begin(), entities.end(),
					[](Entity& e1, Entity& e2) {
				auto p1 = e1.get_component<AnimationComponent>()->priority;
				auto p2 = e2.get_component<AnimationComponent>()->priority;
				return p1 < p2;
			});

		});
}

void RenderUISystem::process_entity(Entity& entity, double dt) {
	auto s = entity.get_component<AnimationComponent>();
	auto p = entity.get_component<PositionComponent>();
	s->animation.clip_sprite();
	s->animation.render(p->position.x, p->position.y);
}
