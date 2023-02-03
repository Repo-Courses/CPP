/* Tiny Ranges Implementation */

namespace predicates {
    auto less_than = [](auto threshold ) { return [=](auto value) { return value < threshold; }; };
    auto greater_than = [](auto threshold) { return [=](auto value) { return value > threshold; }; };
    auto all_of = [](const auto ... preds) { return [=](auto value) { return (preds(value) && ...); }; };
}

namespace actions {
    auto multiply_by = [](auto coef){ return [=](auto value) { return value * coef; }; };
    auto if_then = [](auto predicate, auto action) { return [=](auto value) { if(predicate(value)) value = action(value); return value; }; };
}

namespace views {
    auto odds = []() { int k = 1; return [k]() mutable { int r = k; k += 2; return r; }; };
    auto ints = [](int k=0) { return [k]() mutable { return k++; }; };
}
