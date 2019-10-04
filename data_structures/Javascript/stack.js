class Stack {
	constructor() {
		this._items = [];
	}

	isEmpty() {
		return this._items.length === 0;
	}

	push(item) {
		this._items.push(item);
	}

	pop() {
		return this._items.pop();
	}

	get size() {
		return this._items.length;
	}

	get items() {
		// copy not to access object reference
		return [...this._items];
	}
}

const stack = new Stack();
stack.push(10);
stack.push(20);
stack.push(30);
console.log(stack.items);
console.log(`Size: ${stack.size}`);
stack.pop();
console.log(stack.items);
console.log(`Size: ${stack.size}`);
