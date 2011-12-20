	~/code/emscripten/tools/bindings_generator.py bindings ValueProvider.h -- '{ "create_js_implementations": [{ "class_name": "ConstValueProvider", "implements": ["ValueProvider"]}] }'

	~/code/emscripten/em++ times2.cpp bindings.cpp -include bindings.all.h -o times2.js
 
Change ConstValueProvider.js to this:

	function ConstValueProvider(x) {
	  initObject(this, ConstValueProvider, _emscripten_construct_ConstValueProvider());

	  this.x = x;
	}
	ConstValueProvider.prototype.getValue = function ConstValueProvider_getValue() {
	  return this.x;
	}

Click the button in times2.html.
