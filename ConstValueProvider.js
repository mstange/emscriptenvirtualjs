function ConstValueProvider(x) {
  initObject(this, ConstValueProvider, _emscripten_construct_ConstValueProvider());

  this.x = x;
}
ConstValueProvider.prototype.getValue = function ConstValueProvider_getValue() {
  return this.x;
}