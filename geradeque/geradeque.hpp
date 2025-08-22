#include <cstddef>

template <typename type>
class deque {
public:
	class node {
	public:
		type value;
		node *next = nullptr;
		node *prev = nullptr;
	public:
		node() {};

		node(const type &val) {
			value = val;
		};

		node(const type &val, node *nxt) : next(nxt) {
			value = val;
		};

		node(node *prv, const type &val) : prev(prv) {
			value = val;
		};

		node(node *prv, const type &val, node *nxt) : prev(prv), next(nxt) {
			value = val;
		};
	};

public:
	size_t length = 0;
	node *header = nullptr;
	node *tail = nullptr;

public:
	deque() {};

	deque(const type &value) {
		this->header = this->tail = new node(value);
		this->length++;
	};

	deque(const deque &obj) {
		node *current = obj.header;
        while (current) {
            this->append(current->value);
            current = current->next;
        }
	};

	~deque() {
		this->clear();
	};

	deque &operator=(const deque &obj) {
		if (this == &obj)
			return *this;

		this->clear();
        node *current = obj.header;
        while (current) {
            this->append(current->value);
            current = current->next;
        }
        return *this;
	};

	void push_back(const type &value) {
		node *tmp = new node(value);
		if (this->length == 0) {
			this->header = this->tail = tmp;
		} else {
			this->tail->next = tmp;
			tmp->prev = this->tail;
			this->tail = tmp;
		}
		this->length++;
	};

	void push_front(const type &value) {
		node *tmp = new node(value);
		if (this->length == 0) {
			this->header = this->tail = tmp;
		} else {
			this->header->prev = tmp;
			tmp->next = this->header;
			this->header = tmp;
		}
		this->length++;
	};

	void pop(size_t index) {
		node *tmp;
		if (index == 0) {
			tmp = this->header;
			this->header = this->header->next;
			if (this->header)
				this->header->prev = nullptr;
			else
				this->tail = nullptr;
			delete tmp;
			this->length--;
			return;
		}

		iterator it = this->begin();
		for (size_t i = 0; i < index; i++)
			++it;
		tmp = it.current;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		else
			this->tail = tmp->prev;
		delete tmp;
		this->length--;
	};

	type &pop_back() {
		type *tmp = new type;
		*tmp = this->tail->value;
		this->pop(this->length - 1);
		return *tmp;
	};

	type &pop_front() {
		type *tmp = new type;
		*tmp = this->header->value;
		this->pop(0);
		return *tmp;
	};

	void clear() {
		node *current = this->header;
		while (current) {
			node *next = current->next;
			delete current;
			current = next;
		}
	};

	size_t size() const {
		return this->length;
	};

	class iterator {
		public:
			node *current = nullptr;
		public:
			iterator(node *curr) : current(curr) {};

			type &operator*() const {
				return current->value;
			};

			type *operator->() const {
				return &current->value;
			};

			type value() const {
				return current->value;
			};

			iterator &operator++() {
				this->current = this->current->next;
				return *this;
			};

			iterator operator++(int) {
				iterator tmp = *this;
				this->current = this->current->next;
				return tmp;
			};

			iterator &operator--() {
				this->current = this->current->prev;
				return *this;
			};

			iterator operator--(int) {
				iterator tmp = *this;
				this->current = this->current->prev;
				return tmp;
			};

			bool operator==(const iterator &obj) {
				return this->current == obj.current;
			};

			bool operator!=(const iterator &obj) {
				return this->current != obj.current;
			};
	};

	iterator begin() {
		return iterator(this->header);
	};

	iterator prend() {
		return iterator(this->tail);
	};

	iterator end() {
		return iterator(nullptr);
	};

	static deque &clone(const deque &obj) {
		deque<type> *tmp = new deque<type>();
		node *current = obj.header;
        while (current) {
            tmp->append(current->value);
            current = current->next;
        }
        return *tmp;
	};
};
