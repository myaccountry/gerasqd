#include <cstddef>

template <typename type>
class queue {
private:
	struct _node {
		type value;
		_node *next;
		_node(const type &data) : next(nullptr) {
			value = data;
		};
	};

	size_t length;
	_node *first;

public:
	queue()
		: first(nullptr), length(0) {};

	queue(const queue &obj) : first(nullptr), length(0) {
		_node* tmp = obj.first;
		queue tmp_que;

		while (tmp != nullptr) {
			tmp_que.enqueue(tmp->value);
			tmp = tmp->next;
		}

		while (!tmp_que.is_empty()) {
			this->enqueue(tmp_que.first->value);
			tmp_que.dequeue();
		}
	};

	~queue() {
		while (!this->is_empty())
			this->dequeue();
	};

	void enqueue(const type &value) {
		_node *tmp = new _node(value);
		_node *last = this->first;

		if (last)
			while (last->next)
				last = last->next;
		else
			this->first = tmp;

		if (last)
			last->next = tmp;
		this->length++;
	};

	type &dequeue() {
		type *tmp_val = new type;
		*tmp_val = this->first->value;
		_node *tmp = this->first->next;
		delete this->first;
		this->first = tmp;
		this->length--;
		return *tmp_val;
	};

	type &front() {
		return this->first->value;
	};

	const type &front() const {
		return this->first->value;
	};

	bool is_empty() const {
		return this->first == nullptr; 
	};

	size_t size() const {
		return this->length;
	};
};
