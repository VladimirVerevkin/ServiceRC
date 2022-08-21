# _*_ coding:utf-8 _*_
from flask import Flask, render_template
from flask_socketio import SocketIO, emit

app = Flask(__name__)
#app.config['SECRET_KEY'] = 'D20fndvfMK27^313787-AQl131'

socketio = SocketIO()

socketio.init_app(app)

name_space = '/abcd'


@app.route('/abc')
def get_abc():
    """demo page"""
    return render_template('abc.html')


@app.route('/push')
def push_once():
    """broadcast event generator"""
    event_name = 'abcde'
    broadcasted_data = {'data': "pushed once!"}
    socketio.emit(event_name, broadcasted_data, broadcast=True, namespace=name_space)
    return 'done!'


@socketio.on('connect', namespace=name_space)
def connected_msg():
    """socket client event - connected"""
    print('client connected!')


@socketio.on('disconnect', namespace=name_space)
def disconnect_msg():
    """socket client event - disconnected"""
    print('client disconnected!')


if __name__ == '__main__':
    socketio.run(app)