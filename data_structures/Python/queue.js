class Queue {
	constructor() {
		this._items = [];
	}

	isEmpty() {}

	enqueue(item) {
		this._items.push(item);
	}

	dequeue() {
		return this._items.shift();
	}

	get size() {
		return this._items.length;
	}

	get items() {
		// copy not to access object reference
		return [...this._items];
	}
}

const queue = new Queue();
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
console.log(queue.items);
console.log(`Size: ${queue.size}`);
queue.dequeue();
console.log(queue.items);
console.log(`Size: ${queue.size}`);
