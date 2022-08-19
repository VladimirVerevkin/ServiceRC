# python3
from flask import Flask, render_template
app = Flask(__name__)

@app.route('/')
def index():
    return render_template('index.html')

'''
@app.route("/")
def hello():
    return "Hello World!"
'''
if __name__ == "__main__":
    app.run()
    # app.run(host='0.0.0.0', port=4567)    #сервер публично доступен