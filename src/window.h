#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <panel.h>
#include <memory>
#include <vector>

class Window
{
public:
	class Controller
	{
	public:
		virtual ~Controller() = default;
		virtual bool process(Window &window, int ch) = 0;
		virtual std::string title() const = 0;
	};
	Window(std::unique_ptr<Controller> &&controller, int height, int width);
	~Window();
	void layout(int xpos, int height, int width, bool lframe, bool rframe);
	void set_focus();
	void clear_focus();
	bool process(int ch) { return _controller->process(*this, ch); }
protected:
	void draw_chrome();
private:
	int _xpos = 0;
	int _height = 0;
	int _width = 0;
	std::unique_ptr<Controller> _controller;
	WINDOW *_window = nullptr;
	PANEL *_panel = nullptr;
	bool _has_focus = false;
	bool _lframe = false;
	bool _rframe = false;
};

#endif // WINDOW_H
