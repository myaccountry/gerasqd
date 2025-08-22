#include <cstddef>

template <typename type>
class stack {
private:
	struct _node {
		type value;
		_node *lower;
		_node(const type &data) : lower(nullptr) {
			value = data;
		};
	};

	size_t length;
	_node *peek;

public:
	stack()
		: peek(nullptr), length(0) {};

	stack(const stack &obj) : peek(nullptr), length(0) {
		_node* tmp = obj.peek;
		stack tmp_stk;

		while (tmp != nullptr) {
			tmp_stk.push(tmp->value);
			tmp = tmp->lower;
		}

		while (!tmp_stk.isEmpty()) {
			this->push(tmp_stk.peek());
			tmp_stk.pop();
		}
	};

	~stack() {
		while (!this->isEmpty())
			this->pop();
	};

	void push(const type &value) {
		_node *tmp = new _node(value);
		tmp->lower = this->peek;
		this->peek = tmp;
		this->length++;
	};

	type &pop() {
		type *tmp_val = new type;
		*tmp_val = this->peek->value;
		_node *tmp = this->peek;
		this->peek = this->peek->lower;
		delete tmp;
		this->length--;
		return *tmp_val;
	};

	type &top() {
		return this->peek->value;
	};

	const type top() const {
		return this->peek->value;
	};

	bool isEmpty() {
		return this->peek == nullptr;
	};

	size_t size() const {
		return this->length;
	};

};
