#ifndef EDITOR_EDITOR_H
#define EDITOR_EDITOR_H

#include "controller.h"
#include "document.h"
#include "update.h"
#include "cursor.h"

namespace Editor {
class Controller : public ::Controller
{
public:
	Controller(std::string targetpath);
	virtual void paint(WINDOW *view, bool active) override;
	virtual bool process(WINDOW *view, int ch, App &app) override;
	virtual bool poll(WINDOW *view, App &app) override { return true; }
	virtual std::string title() const override { return _targetpath; }
protected:
	void paint_line(WINDOW *view, row_t v);
	bool line_is_visible(line_t index) const;
	void reveal_cursor();
	void update_dimensions(WINDOW *view);
private:
	std::string _targetpath;
	Document _doc;
	Update _update;
	Cursor _cursor;
	bool _last_active = false;
	WINDOW *_last_dest = nullptr;
	// What are the width and height of the viewrect?
	size_t _width = 0;
	size_t _height = 0;
	size_t _halfheight = 0;
	size_t _maxscroll = 0;
	// What is the vertical position of the viewrect?
	size_t _scrollpos = 0;
};
} // namespace Editor

#endif // EDITOR_EDITOR_H