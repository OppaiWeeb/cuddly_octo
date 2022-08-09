pipeline {
    agent none
    stages {
        stage('Check norme') {
        agent {docker 'epitechcontent/epitest-docker:latest'}
        steps {
            sh 'mkdir -p build && cd build'
            sh 'cmake ..'
            sh 'make'
            }
        }
    }
}
