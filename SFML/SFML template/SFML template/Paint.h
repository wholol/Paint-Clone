#pragma once
#include <SFML\Graphics.hpp>


struct Paint {

	Paint();
	static constexpr uint8_t minbrushradius = 8;		//maximum radius of the brush.
	static constexpr uint8_t maxbrushradius = 50;	//minimum radius of the brush.
	int mouseposx; int mouseposy;

	
	sf::CircleShape circle;		//create circle object for th paint.
	
	void ChangeBrushSize();
	virtual void ToolbarCollisionDetection() = 0;
	virtual void drawpaint(sf::RenderWindow& createwindow) = 0;
	virtual void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) = 0;

};

struct Red :public Paint {	

	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse , sf::RenderWindow &createwindow) override;

};

struct Yellow : public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct Blue :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct Black :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct Magenta :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct Cyan :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct Green :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};

struct White :public Paint {
	void ToolbarCollisionDetection() override;
	void drawpaint(sf::RenderWindow &createwindow) override;
	void setMousePos(const sf::Mouse& mouse, sf::RenderWindow &createwindow) override;
};