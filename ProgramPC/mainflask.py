# python3
from flask import Flask, render_template
from flask_socketio import SocketIO, emit
app = Flask(__name__)
app.config['SECRET_KEY'] = 'kod!'

socketio = SocketIO(app)

#socketio.init_app(app)

#name_space = '/abcd'

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/test')
def test():
    return render_template('test.html')

@socketio.event
def my_event(message):
    emit('my response', {'data': 'got it!'})

'''
@app.route("/")
def hello():
    return "Hello World!"
'''
if __name__ == "__main__":
    socketio.run(app)
    #app.run()
    # app.run(host='0.0.0.0', port=4567)    #сервер публично доступен